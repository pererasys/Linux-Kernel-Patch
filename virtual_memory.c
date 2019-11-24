#include <linux/kernel.h>

SYSCALL_DEFINE1(virtual_memory, void*, p)
{
  struct task_struct *task = current;
  struct vm_area_struct *cur_area = 0;
  for (cur_area = task->mm->mmap; cur_area; cur_area = cur_area->vm_next) {
    if (p > cur_area->vm_start && p < cur_area->vm_end) {
      return cur_area->vm_flags;
    }
  }
  return 0;
}
