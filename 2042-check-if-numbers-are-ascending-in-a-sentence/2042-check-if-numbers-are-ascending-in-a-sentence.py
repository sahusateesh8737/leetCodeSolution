class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        numbers = []

        for token in s.split():
            if token.isdigit():
                numbers.append(int(token))
        

        for i in range(1 , len(numbers)):
            if numbers[i] <= numbers[i -1]:
                return False
        
        return True