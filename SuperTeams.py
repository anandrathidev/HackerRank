# -*- coding: utf-8 -*-
"""
Created on Tue Dec 12 11:29:42 2017

@author: rb117
"""

import itertools

skills = "mcmz"
skillSet = set(skills )


IDskill = {v: k for v, k in enumerate(skills)}


skillListID = {}
for eachSkill in skillSet:
  skillListID[eachSkill] = [ids for ids, skill in IDskill.items() if skill == eachSkill]



def differentTeams(skills):
  p = skills.count('p')
  c = skills.count('c')
  m = skills.count('m')
  b = skills.count('b')
  z = skills.count('z')
  listskill = [p,c,m,b,z]
  return min(listskill)