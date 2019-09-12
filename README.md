# vc6qpudisas

Disassemble machine codes of VideoCore VI QPU with a help of Mesa library.


## Setting up

```
git clone https://gitlab.freedesktop.org/mesa/mesa.git --depth=1
cd mesa/
mkdir build/
cd build/
meson ..
ninja src/broadcom/qpu/libbroadcom_qpu.a src/util/libmesa_util.a
cd ../../
git clone https://github.com/Terminus-IMRC/vc6qpudisas.git
cd vc6qpudisas/
mkdir build/
cd build/
cmake .. -DCMAKE_PREFIX_PATH="$(realpath ../../mesa);$(realpath ../../mesa/build)"
make
```


## Example

```
$ ./vc6qpudisas <<<'0x3c00318038811000'
add  r0, r1, r2      ; nop
```
