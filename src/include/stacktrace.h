#ifndef STACKTRACE_H
#define STACKTRACE_H

void pstack(int fd, unsigned skip = 0);
void pstack_maybe(void);
void diediedie(void);
void handle_unexpected(void);
void handle_signal(int s);

#endif // STACKTRACE_H
