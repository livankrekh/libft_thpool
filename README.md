# libft_thpool

### Simple C multithread project. Library for manage pthread pool

## Compile library
```
> make
```
Result: libft_thpool.a

## Library functions
Function to create a pool struct named `t_tp_thread`
```c
t_tp_thread *tp_create(int count, char flag);
```
Function to execute function on created pthread pool
```c
int tp_exec_queue_add(t_tp_thread *queue, void *(*f)(void *), void *data);
```
Function for waiting end of excecution of pthread pool
```c
int tp_wait_for_queue(t_tp_thread *queue);
```
Function for get number of processor cores
```c
int tp_get_nbr_proc(void);
```
