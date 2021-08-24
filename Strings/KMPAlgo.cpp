#include <bits/stdc++.h>

void computeLPSArray(char *pat, int M, int *lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(char *pat, char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int lps[M];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < N)
	{
		if (pat[i] == pat[j])
		{
			i++;
			j++;
		}
		if (j == M)
		{
			cout << "pattern exists at " << i - j;
			j = lps[j - 1];
		}
		else if (i < N && pat[j] != txt[i])
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
				i++;
		}
	}
}
void calculateRes(string s, int length, vector<int> &res)
	/* check your own implementation of calculateLps file for this */

	// Driver program to test above function
	int main()
{
	char txt[] = "ABABDABACDABABCABAB";
	char pat[] = "ABABCABAB";
	KMPSearch(pat, txt);
	return 0;
}
