#समावेश <stdio.h>
#समावेश <string.h>
/* HTTP: read the request line and count the header lines of a request */
पूर्णांक मुख्य(व्योम) {
  अक्षर text[] = "GET /index.html HTTP/1.1\r\nHost: example.com\r\nAccept: text/html\r\nConnection: close\r\n\r\n";
  अक्षर method[16], path[64], version[16];
  माला_पूछो(text, "%15s %63s %15s", method, path, version);
  पूर्णांक headers = 0;
  क्रम (अक्षर *line = म_माला(text, "\r\n") + 2; म_भेदन(line, "\r\n", 2) != 0; line = म_माला(line, "\r\n") + 2) headers++;
  म_लिखो("%s %s %s, %d headers\n", method, path, version, headers);
  वापस 0;
}
