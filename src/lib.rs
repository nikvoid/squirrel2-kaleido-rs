#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod tests {
    use super::sq_open;
    use super::sq_close;

    #[test]
    fn build_check() {
        unsafe {
            let vm = sq_open(1024);
            sq_close(vm);
        }
    }
}