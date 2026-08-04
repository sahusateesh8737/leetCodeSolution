class Solution:
    def countValidPrefixes(self, s: str) -> int:
        validCount = 0
        count0 = 0
        count1 = 0
        for char in s:
            if char == '0':
                count0 +=1
            else:
                count1 +=1
            if abs(count0 - count1) <=1:
                validCount +=1
        return validCount
        