def heapreplace(heap, item):
    r_item = heap[0]
    heap[0] = item
    siftup(heap, 0)
    return r_item


def siftup(heap, pos):
    # Наибольший элемент падает
    end_pos = len(heap)
    start_pos = pos
    new_item = heap[pos]
    child_pos_left = 2 * pos + 1
    while child_pos_left < end_pos:
        child_pos_right = child_pos_left + 1
        if child_pos_right < end_pos and not heap[child_pos_left] < heap[child_pos_right]:
            child_pos_left = child_pos_right
        # Переместите младшего ребенка вверх
        heap[pos] = heap[child_pos_left]
        pos = child_pos_left
        child_pos_left = 2 * pos + 1
    heap[pos] = new_item
    siftdown(heap, start_pos, pos)


def siftdown(heap, start_pos, pos):
    # Следуйте по пути к корню, двигая родителей вниз, пока не найдете место, подходящее для нового элемента.
    new_item = heap[pos]
    while pos > start_pos:
        parent_pos = (pos - 1) // 2
        parent = heap[parent_pos]
        if new_item < parent:
            heap[pos] = parent
            pos = parent_pos
            continue
        break
    heap[pos] = new_item
