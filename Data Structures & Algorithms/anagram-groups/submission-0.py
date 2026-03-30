class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        listGroup = defaultdict(list)
        for str in strs:
            freq = [0] * 26
            for ch in str:
                index = ord(ch) - ord('a')
                freq[index] += 1

            key = tuple(freq)
            listGroup[key].append(str)

        return list(listGroup.values())