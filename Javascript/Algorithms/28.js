/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
let strStr = (haystack, needle) => {
  const lenh = haystack.length, lenn = needle.length;

  if (lenn == 0) return 0;

  if (lenn > lenh) return -1;

  const diff = lenh - lenn;
  for (let i = 0; i < lenh; i++) {
    if (i <= diff) {
      let found = true;
      for (let j = 0; j < lenn; j++) {
        if (haystack[i + j] != needle[j]) {
          found = false;
          break;
        }
      }
      if (found) return i;
    }
  }
  return -1;
};