//knuth morris pratt
vector<int> LPS(string pat) {
    int M = pat.length();
    vector<int> lps(M);
    int len = 0, i=1;
    lps[0] = 0;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } 
        else {
            if (len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
    return lps;
}

void KMP(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();
    vector<int> lps = LPS(pat);
    int i = 0, j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } 
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i = i + 1;
        }
    }
}
