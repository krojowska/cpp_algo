#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//1. return true if x is palindrome integer
bool isPalindrome(int x) {
	/*string s=(to_string(x));
	string z;
	for (int i=s.length()-1; i<s.length(); i--){
		z+=s[i];
	}
	if(s==z) return true;
	else return false;*/
	if (x < 0) return false;

	long y = 0;
	int initial = x;

	while (x > 0) {
		y = y * 10 + x % 10;
		x /= 10;
	}

	return initial == y;
}

//2. Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
int strStr(string haystack, string needle) {
	/*if (needle == "") return 0;
	for(int i=0; i<haystack.size(); i++){
		if(haystack.find(needle)) return i;
	}
	return -1;*/

	return haystack.find(needle);
}

//3. return the index if the target is found. If not, return the index where it would be if it were inserted in order.
int searchInsert(vector<int>& nums, int target) {
	int index = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == target) return i;
		if (nums[i] < target) {
			index++;
		}

	}
	return index;
}

//4. return the length of the last word in the string.
int lengthOfLastWord(string s) {
	int count = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] == ' ' && count == 0) continue;
		if (s[i] != ' ') count++;
		else break;
	}
	return count;
}

//5. Find that single one in table where every element appears twice except for one. 
int singleNumber(vector<int>& nums) {
	int except = 0;
	for (int i = 0; i < nums.size(); i++) {
		except ^= nums[i];
	}
	return except;
}

//6. Return the majority element which appears more than n / 2 times, n == nums.length
int majorityElement(vector<int>& nums) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	return nums[n / 2];
}
// 7. Return true if any value appears at least twice in the array, and return false if every element is distinct.
bool containsDuplicate(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 1; i++) {
		if (nums[i] == nums[i + 1]) return true;
	}
	return false;
}

//8. Check if two strings are anagrams
bool isAnagram(string s, string t) {
	//if(s.size() != t.size())
	//    return 0;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	if (s == t) return true;
	else return false;

}

// 9 . Find the first non-repeating character in it and return its index. If it does not exist, return -1
int firstUniqChar(string s) {
	unordered_map<char, int>mymap;
	for (int i = 0; i < s.length(); i++) {
		mymap[s[i]]++;
	}
	for (int i = 0; i < s.length(); i++) {
		if (mymap[s[i]] == 1) {
			return i;
		}
	}
	return -1;
}

//10. Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
	string str = "", str2;
	for (int i = 0; i < word1.size(); i++) {
		str += word1[i];
	}
	for (int i = 0; i < word2.size(); i++) {
		str2 += word2[i];
	}
	cout << str<<"\n";
	cout << str2<<"\n";
	return (str == str2);

}

int main()
{
	int check;
	cout << "1. Return true if x is palindrome integer. \n";
	cout << "2. Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.\n";
	cout << "3. Return the index if the target is found. If not, return the index where it would be if it were inserted in order. \n";
	cout << "4. Return the length of the last word in the string. \n";
	cout << "5. Find that single one in table where every element appears twice except for one. \n";
	cout << "6. Return the majority element which appears more than n / 2 times, n == nums.length \n";
	cout << "7. Return true if any value appears at least twice in the array, and return false if every element is distinct. \n";
	cout << "8. Check if two strings are anagrams \n";
	cout << "9 . Find the first non-repeating character in it and return its index. If it does not exist, return -1 \n";
	cout << "10. Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise. \n";

	cout << "Choose number of task: ";
	cin >> check;
	if (check == 1) {
		int integer = 121;
		bool answer1 = isPalindrome(integer);
		cout << answer1;
	}
	else if (check == 2) {
		string h = "hello";
		string n = "lo";
		int answer2 = strStr(h, n);
		cout << answer2;
	}
	else if (check == 3) {
		vector<int> vector = { 1,2,3,4,6 };
		int target = 5;
		int answer3 = searchInsert(vector, target);
		cout << answer3;
	}
	else if (check == 4) {
		string s = "Hello Bonjour how are you? I hope everything is so good ";
		int answer4 = lengthOfLastWord(s);
		cout << answer4;
	}
	else if (check == 5) {
		vector<int> vector2 = { 2,2,4,4,6,5,5 };
		int answer5 = singleNumber(vector2);
		cout << answer5;
	}
	else if (check == 6) {
		vector<int> nums = { 7,7,4,7,7,5,7,6 };
		int answer6 = majorityElement(nums);
		cout << answer6;
	}
	else if (check == 7) {
		vector<int> vector2 = { 7,1,3,4,6,5,9,6 };
		int answer7 = containsDuplicate(vector2);
		cout << answer7;
	}
	else if (check == 8) {
		string string1 = "state";
		string string2 = "taste";
		bool answer8 = isAnagram(string1, string2);
		cout << answer8;
	}
	else if (check == 9) {
		string inp = "everyonelovecutecats";
		int answer9 = firstUniqChar(inp);
		cout << answer9;
	}
	else if (check == 10) {
		vector<string> word1 = {"a", "penguin", "is", "black", "aha"};
		vector<string> word2 = { "a", "penguin", "isn't", "black", "aha" };
		bool answer10 = arrayStringsAreEqual(word1, word2);
		cout << answer10;
	}


}

