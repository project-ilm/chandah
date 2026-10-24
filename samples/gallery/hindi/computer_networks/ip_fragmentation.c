#समावेश <stdio.h>
/* IPv4: fragmenting a 4000-byte datagram (20-byte header) for a 1500-byte MTU; offsets are in 8-byte units */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक योग_2 = 4000, header = 20, largest = 1500, तथ्य = योग_2 - header, room = (largest - header) / 8 * 8, offset = 0;
  जबतक (तथ्य > 0) {
    पूर्णांक आकार = तथ्य > room ? room : तथ्य, more = तथ्य > room;
    म_लिखो("length %d offset %d more %d\n", आकार + header, offset / 8, more);
    offset += आकार; तथ्य -= आकार;
  }
  वापस 0;
}
