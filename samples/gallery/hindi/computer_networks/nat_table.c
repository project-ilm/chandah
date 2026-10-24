#समावेश <stdio.h>
/* NAT: private address and port pairs mapped to ports of one public address, both ways */
पूर्णांक मुख्य(व्योम) {
  अचिन्हित private_address[3] = {0xC0A80002, 0xC0A80003, 0xC0A80002}, private_port[3] = {5000, 5000, 6000}, public_port[3];
  पूर्णांक count = 0;
  क्रम (पूर्णांक index = 0; index < 3; index++) { public_port[count++] = 40000 + index; म_लिखो("192.168.0.%u:%u -> 203.0.113.9:%u\n", private_address[index] & 255, private_port[index], public_port[index]); }
  अचिन्हित arriving = 40001;
  क्रम (पूर्णांक index = 0; index < count; index++)
    अगर (public_port[index] == arriving) म_लिखो("reply to %u goes to 192.168.0.%u:%u\n", arriving, private_address[index] & 255, private_port[index]);
  वापस 0;
}
