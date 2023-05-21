# HardwareAcceleratedECC-PointMultiplication
This repository contains accelerated hardware IPs for scalar and double point multiplication operations in elliptic curve cryptography (ECC). These IPs are designed using high-level synthesis (HLS) and incorporates a novel approach to recode the scalars using Radix-2 Windowing arithmetic. This technique reduces the number of required adding and doubling operations in the binary field, resulting in improved performance, all information related to this technique can be found at: https://www.researchgate.net/publication/348976216_Radix-2w_Arithmetic_for_Scalar_Multiplication_in_Elliptic_Curve_Cryptography

In addition to the hardware IP, the repository provides high-level software drivers to facilitate seamless integration of the accelerated IP into high-level designs. The drivers enable high-level implementations of elliptic curve Diffie-Hellman (ECDH) and elliptic curve digital signature algorithm (ECDSA). These software implementations leverage the accelerated IP to achieve significant speedup in ECC computations.

Key Features:

Accelerated hardware IP for scalar and double point multiplication in ECC.
Radix-2 Windowing arithmetic approach for efficient scalar recoding.
Reduction in the number of adding and doubling operations in the binary field.
HLS-based design for improved productivity and portability.
High-level software drivers for easy integration into high-level designs.
Support for elliptic curve Diffie-Hellman (ECDH) and elliptic curve digital signature algorithm (ECDSA) software implementations.
The repository aims to provide a comprehensive solution for accelerating ECC operations using a hardware IP design that leverages an optimized scalar recoding technique. By offering high-level software drivers, it enables seamless integration into high-level designs and facilitates the implementation of ECDH and ECDSA protocols with improved performance and efficiency.

## Development Environment
/home/ghani/git/HardwareAcceleratedECC-PointMultiplication/PYNQ-MAP.png

