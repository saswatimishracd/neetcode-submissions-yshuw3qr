class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        #base condition
        if not strs:
            return ""
        commonPrefix = strs[0];
        for str in strs[1:]:
            while not str.startswith(commonPrefix):
                commonPrefix = commonPrefix[:-1]
                if commonPrefix == "":
                    return ""
        return commonPrefix