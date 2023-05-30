# Pipex Project

## Introduction

The Pipex project is about handling pipes in C programming. The program is executed as follows: `./pipex file1 cmd1 cmd2 file2`. It must take 4 arguments:

- `file1` and `file2` are file names.
- `cmd1` and `cmd2` are shell commands with their parameters.

It must behave exactly the same as the shell command below: `$> < file1 cmd1 | cmd2 > file2`.

## Mandatory Part

- Program name: pipex
- Turn in files: Makefile, *.h, *.c
- Makefile: NAME, all, clean, fclean, re
- Arguments: file1 cmd1 cmd2 file2
- External functions: open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid
- ft_printf and any equivalent YOU coded
- Libft authorized: Yes

## Bonus Part

You will get extra points if you:

- Handle multiple pipes. This: `$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2` should behave like: `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`.
- Support « and » when the first parameter is "here_doc". This: `$> ./pipex here_doc LIMITER cmd cmd1 file` should behave like: `cmd << LIMITER | cmd1 >> file`.

The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.
