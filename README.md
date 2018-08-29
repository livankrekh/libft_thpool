# libft_thpool

### Simple C multithread project. Library for manage pthread pool

## Compile library
```
> make
```
Result: libft_thpool.a

## Library functions
Function to create a pool struct named `t_tp_thread`
`int count` - number of threads
`char flag` - `TP_ON_EXEC` (execute pool on new task adding) or `TP_ON_START` (execution on pool creating)
```c
t_tp_thread *tp_create(int count, char flag);
```
Function to execute task (function f) on created pthread pool
`t_tp_thread *queue` - pthread pool
`void *(*f)(void *)` - task, that need to execute on pool
`void *data` - argument for `void *(*f)(void *)` function
```c
int tp_exec_queue_add(t_tp_thread *queue, void *(*f)(void *), void *data);
```
Function for waiting end of execution of pthread pool
`t_tp_thread *queue` - pthread pool
```c
int tp_wait_for_queue(t_tp_thread *queue);
```
Function for get number of processor cores
```c
int tp_get_nbr_proc(void);
```
