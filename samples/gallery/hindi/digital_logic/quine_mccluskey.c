#समावेश <stdio.h>
/* minimisation: prime implicants by the tabular (Quine-McCluskey) method for f = sum of minterms 0,1,2,5,6,7,8,9,10,14 */
पूर्णांक मान[64], mask[64], used[64], count = 0;
पूर्णांक मुख्य(व्योम) {
  पूर्णांक minterms[] = {0, 1, 2, 5, 6, 7, 8, 9, 10, 14};
  क्रम (पूर्णांक index = 0; index < 10; index++) { मान[count] = minterms[index]; mask[count++] = 0; }
  क्रम (पूर्णांक start = 0, end = count; start < end; start = end, end = count)
    क्रम (पूर्णांक first = start; first < end; first++)
      क्रम (पूर्णांक second = first + 1; second < end; second++) {
        पूर्णांक differ = मान[first] ^ मान[second];
        अगर (mask[first] != mask[second] || (differ & (differ - 1))) जारी;
        used[first] = used[second] = 1;
        पूर्णांक known = 0;
        क्रम (पूर्णांक index = end; index < count; index++) अगर (mask[index] == (mask[first] | differ) && मान[index] == (मान[first] & ~differ)) known = 1;
        अगर (!known) { मान[count] = मान[first] & ~differ; mask[count++] = mask[first] | differ; }
      }
  क्रम (पूर्णांक index = 0; index < count; index++) {
    अगर (used[index]) जारी;
    क्रम (पूर्णांक bit = 3; bit >= 0; bit--) अक्षर_दो(mask[index] >> bit & 1 ? '-' : '0' + (मान[index] >> bit & 1));
    अक्षर_दो(' ');
  }
  म_लिखो("\n");
  वापस 0;
}
