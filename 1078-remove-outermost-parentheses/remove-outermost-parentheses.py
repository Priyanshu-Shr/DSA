class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans = ""
        open = 0

        for ch in s:
            if ch == '(':
                open += 1

                if open >= 2:
                    ans += ch

            else:
                if open >= 2:
                    ans += ch

                open -= 1

        return ans