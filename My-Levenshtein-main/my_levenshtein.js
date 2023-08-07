s1 = "";
s2 = "";

function my_levenshtein(s1, s2) {
    var diff = 0
    if (s1.length == s2.length) {
        for (i = 0; i < s1.length; i++) {
            if (s1[i] != s2[i]) {
                diff++;
            } 
        }
return diff;
    } else {
        return diff = -1;
    }
};

my_levenshtein(s1, s2);
// Your function must take in 2 strings with the exact number of characters and return an integer representing
// the difference between them.

// If your parameters are not the same size then your function will return -1.

// If the two strings are the same size, you must then iterate through each string and determine 
// which characters are different. Each time there is a difference, it counts as 1.
