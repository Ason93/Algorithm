#!usr/bin/env python
# -*- coding:utf-8 -*-
from collections import deque

graph = {}
graph["you"] = ["alice", "bob", "claire"]
graph["bob"] = ["anuj", "peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["thom", "jonny"]
graph["anuj"] = []
graph["peggy"] = []
graph["thom"] = []
graph["jonny"] = []

def person_is_seller(person):
    return person[-1] == 'm'

def search(name):
    search_queue = deque() # 创建一个队列
    search_queue += graph[name] # 将你的邻居加入到这个搜索队列中
    searched = [] # 这个数组用于记录检查过的人

    while search_queue: # 只要队列不为空
        person = search_queue.popleft() # 就取出其中的第一个人
        if person not in searched: # 仅当这个人没有检查过时才检测
            if person_is_seller(person): # 检查这个是否为芒果经销商
                print(person + " is a mango seller! ") # 是芒果销售商
                return True
            else:
                searched.append(person) # 将这个人标记为检查过
                search_queue += graph[person] #不是芒果销售商。将这个人的朋友都加入搜索队列
    print("None mango seller!")
    return False

if __name__ == "__main__":
    search("you")


