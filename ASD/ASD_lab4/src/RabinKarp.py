def RabinKarp(pat, txt, q=1000000007):
    m, n = len(pat), len(txt)
    if m != n:
        return []
    j = h_p = h_t = 0
    h = 1
    ans = []
    for _ in range(m - 1):  # таблица нужных размеров
        h = (h * 256) % q

    for i in range(m):
        h_p = (256 * h_p + ord(pat[i])) % q
        h_t = (256 * h_t + ord(txt[i])) % q

    for i in range(n - m + 1):
        if h_p == h_t:
            for j in range(m):
                if txt[i + j] != pat[j]:
                    break
            j += 1
            if j == m:
                ans.append(i)
        if i < n - m:
            h_t = (256 * (h_t - ord(txt[i]) * h) + ord(txt[i + m])) % q
            if h_t < 0:
                h_t = h_t + q
    return ans
