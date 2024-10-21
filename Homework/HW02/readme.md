# Homework 2 Description

## Problem Description
Suppose we can buy chocolate bars from the vending machine for $1 each. Inside every chocolate bar is a coupon. We can redeem 7 coupons for 1 chocolate bar from the machine. We would like to know how many chocolate bars can be eaten, including those redeemed via coupon, if we have *n* dollars.

### Example
If we have $20, then we can initially buy 20 chocolate bars. This gives us 20 coupons. We can redeem 14 coupons for 2 additional chocolate bars. These two additional chocolate bars have 2 more coupons, so we now have a total of 8 coupons when added to the 6 left over from the original purchase. This gives us enough to redeem for 1 final chocolate bar. As a result, we now have 23 chocolate bars and 2 leftover coupons.

## Task
Write a recursive solution to this problem that:
- Inputs from the user the number of dollars to spend on chocolate bars.
- Outputs how many chocolate bars you can collect after spending all your money and redeeming as many coupons as possible.
- Your recursive function will be based upon the number of coupons owned.
