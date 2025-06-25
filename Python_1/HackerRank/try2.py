if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    avg=0
    for n,s in student_marks.copy().items():
        if n==query_name:
            for i in s:
                avg+=i
            avg=avg/len(s)
    print('%.2f'%avg)
