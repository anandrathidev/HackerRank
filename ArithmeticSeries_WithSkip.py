# -*- coding: utf-8 -*-
"""
Created on Tue Dec 12 13:47:04 2017

@author: rb117
"""

def findroot(k):
       A=1
       B=1
       C=-1*2*k
       R1 = (-B+ np.sqrt(B^2-4*A*C))/ (2*A )
       R2 = (-B- np.sqrt(B^2-4*A*C))/ (2*A )
       if R1>0:
          return R1
       if R2>0:
          return R2


def maxMoney(n,k):
       myroot = round(findroot(k))
       tot=n*(n+1)/2 
       rtot = myroot*(myroot+1)/2
       answer = tot-myroot
       return (answer % (10^9+7) )


maxMoney(3,3)
maxMoney(4,10)
