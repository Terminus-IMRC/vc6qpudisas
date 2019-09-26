#include <stdio.h>
#include <stdlib.h>

/* From Mesa */
#include <broadcom/qpu/qpu_disasm.h>
#include <util/ralloc.h>

int main(void)
{
    struct v3d_device_info devinfo = {
        .ver = 42,
    };

    char line[4096];

    while (fgets(line, sizeof(line), stdin) != NULL) {
        const unsigned long long insn = strtoull(line, NULL, 0);

        const char *disasm = v3d_qpu_disasm(&devinfo, insn);

        puts(disasm);

        ralloc_free((void*) disasm);
    }

    return 0;
}
