#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <ctype.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <unistd.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/socket.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/wait.h>
/* the socket API: a connected pair of sockets; the child answers each message in capitals */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਪੂਰਨ ਸਿਰੇ[2];
  socketpair(AF_UNIX, SOCK_STREAM, 0, ਸਿਰੇ);
  ਜੇ (fork() == 0) {
    ਅੱਖਰ ਪਾਠ[64]; ssize_t ਲੰਮਾਈ = ਪਠ(ਸਿਰੇ[1], ਪਾਠ, ਆਕਾਰ ਪਾਠ);
    ਲਈ (ssize_t index = 0; index < ਲੰਮਾਈ; index++) ਪਾਠ[index] = ਵੱਡਾ_ਅੱਖਰ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)ਪਾਠ[index]);
    ਬਾਹਰ_ਨਿਕਲੋ(ਲਿਖ(ਸਿਰੇ[1], ਪਾਠ, ਲੰਮਾਈ) == ਲੰਮਾਈ ? 0 : 1);
  }
  ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ = "hello over a socket";
  ਅੱਖਰ ਜਵਾਬ[64] = {0};
  ਜੇ (ਲਿਖ(ਸਿਰੇ[0], ਸੁਨੇਹਾ, ਲੜੀ_ਲੰਬਾਈ(ਸੁਨੇਹਾ)) < 0 || ਪਠ(ਸਿਰੇ[0], ਜਵਾਬ, ਆਕਾਰ ਜਵਾਬ - 1) < 0) ਵਾਪਸ 1;
  wait(ਨਿਰਾ);
  ਲਿਖੋ("%s\n", ਜਵਾਬ);
  ਵਾਪਸ 0;
}
