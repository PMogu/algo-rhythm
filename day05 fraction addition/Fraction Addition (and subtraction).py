class Solution(object):
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        num = 0
        denom = 1
        i = 0
        n = len(expression)

        while i < n:
            sign = 1
            if expression[i] in '+-':
                if expression[i] == '-':
                    sign = -1
                i +=1

            curr_num = 0
            while i < n and expression[i].isdigit():
                curr_num = curr_num * 10 + int(expression[i])
                i += 1
            curr_num *= sign

            i += 1

            curr_denom = 0
            while i < n and expression[i].isdigit():
                curr_denom = curr_denom * 10 + int(expression[i])
                i += 1

            num = num * curr_denom + curr_num * denom
            denom = denom * curr_denom

            g = self.find_gcd(abs(num), abs(denom))
            num //= g
            denom //= g

        return f"{num}/{denom}"

    def find_gcd(self, a, b):
        while b:
            a, b = b, a % b
        return abs(a)