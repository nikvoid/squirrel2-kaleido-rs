extern crate bindgen;
extern crate cmake;

use std::env;
use std::path::PathBuf;
use std::fs;

use glob::glob;
use cmake::Config;

fn main() {
    let dst = Config::new("sq2")
        .no_build_target(true)
        .build();

    let mut dst_lib = dst.clone();
    dst_lib.push("lib");
    fs::create_dir(&dst_lib).ok();

    // Copy compiled lib to make it possible for rustc to find it
    for entry in glob(&format!("{}/build/**/*.lib", dst.display())).expect("Failed to read glob pattern") {
        match entry {
            Ok(path) => {
                let filename = path.file_name().unwrap().to_str().unwrap();
                let mut dst = dst_lib.clone();
                dst.push(filename);
                fs::copy(path, dst).unwrap()
            }
            Err(e) => panic!("{:?}", e),
        };
    }

    println!("cargo:rustc-link-search=native={}", dst_lib.display());
    println!("cargo:rustc-link-lib=static=squirrel");

    let bindings = bindgen::Builder::default()
        .header("wrapper.h")
        .trust_clang_mangling(false)
        .generate()
        .expect("Unable to generate bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}