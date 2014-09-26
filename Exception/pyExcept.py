# -*- coding: utf-8 -*-
"""
Created on Fri Sep 26 10:52:37 2014

@author: Yinxy
"""

try:
    print 1
    raise Exception("ff")
except Exception as e:
    print e
except:
    print 'haha'
    
    