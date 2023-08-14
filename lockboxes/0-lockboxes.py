#!/usr/bin/python3
'''
This module is a script to determines if all the boxes can be opened.

Args:
  boxes (list): list of lists
'''


def canUnlockAll(boxes):
    length = len(boxes)
    if not boxes:
        return False
    if length == 1:
        return True
    if not boxes[0]:
        return False
    # 探索キューを作成
    queue = list(boxes[0])
    opened_boxes = {0}

    while queue:
        popped_key = queue.pop(0)
        # popped_keyがboxesのlengthをこえていないかチェック（IndexError回避）
        if popped_key not in opened_boxes and 0 <= popped_key < length:
            opened_boxes.add(popped_key)
            collected_keys = list(boxes[popped_key])
            for key in collected_keys:
                if key not in opened_boxes and key not in queue:
                    queue.append(key)

    box_list = set(range(length))

    return opened_boxes == box_list
