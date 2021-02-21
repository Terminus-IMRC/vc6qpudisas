# vc6qpudisas

Disassemble machine codes of VideoCore VI QPU.


## Setting up

First, you need to build the disassembler in [Mesa 3d](https://www.mesa3d.org/):

```shell
$ git clone https://gitlab.freedesktop.org/mesa/mesa.git --depth=1
$ cd mesa/
$ mkdir build/
$ cd build/
$ meson .. -Dgallium-drivers=v3d -Dvulkan-drivers=broadcom -Dplatforms=x11
$ ninja src/broadcom/qpu/libbroadcom_qpu.a src/util/libmesa_util.a
$ cd ../../
```

After that, vc6qpudisas can be built as:

```shell
$ git clone https://github.com/Terminus-IMRC/vc6qpudisas.git
$ cd vc6qpudisas/
$ mkdir build/
$ cd build/
$ cmake .. -DCMAKE_PREFIX_PATH="$(realpath ../../mesa);$(realpath ../../mesa/build)"
$ make
```


## Usage

```shell
$ ./vc6qpudisas <<<'0x54001f4038f91fbf'
add  r0, r1, r2      ; fmul  rf61, rf62, rf63
```

See
[mesa/src/broadcom/qpu/tests/qpu_disasm.c](https://gitlab.freedesktop.org/mesa/mesa/blob/master/src/broadcom/qpu/tests/qpu_disasm.c)
for other examples.
