#include "linux-syscall-support/linux_syscall_support.h"

static int __errno;
int *__errno_location() { return &__errno; }

// Allocate this in .data rather than on the stack
// because otherwise this program has a RW data segment with file size 0
// which breaks on qemu linux-user < 4.1.0
static char line[2] = { 0, '\n' };

void _start() {
  for(*line = '0'; *line < '5'; (*line)++) {
    sys_write(1, line, sizeof(line));
  }

  sys__exit(0);
}
