def solution(lines):
    answer = 0
    times = [] // 문자열 시간들을 시작초, 종료초(실수형)로 저장하는 배열
    
    for line in lines:
        line_arr = line.split(' ') // 공백 기준으로 자르기
        time_arr = line_arr[1].split(':') // : 기준으로 시, 분, 초 자르기
        end_time = float(time_arr[0])*60*60 + float(time_arr[1])*60 + float(time_arr[2])
        start_time = end_time - float(line_arr[2][:-1]) +0.001 // 0.001초 추가;; 이거때문에 꽤 오래 걸린듯..
        times.append([start_time, end_time]) // 시작 시간과 종료 시간을 배열에 넣는다
    times.sort() // 시작 시간 빠른 순서로 정렬 (입력값이 정렬된건지 모르겠따)
    
    for time in times: // times에 저장된 시간들을 순회하면서
        cnt = 0
        for tmp in times: // 이중반복문으로 비교 1. 시작시간 ~ 시작시간+1초를 확인
            if tmp[0] > time[0]+1: // 비교할 시작시간이 현재 시작시간+1초보다 크면 브레이크
                break
            if tmp[0] <= time[0] and tmp[1] >= time[0]: // 구간 비교
                cnt +=1
            elif tmp[0] >= time[0] and tmp[0] <= time[0]+1: // 또는 구간비교
                cnt += 1
        if cnt > answer: // max값 재설정
            answer = cnt
        cnt = 0
        for tmp in times: // 비교 2. 시작시간-1초 ~ 시작시간 구간을 확인
            if tmp[0] > time[0]: // 비교할 시작시간이 현재 시작시간보다 크면 브레이크
                break
            if tmp[1] > time[0]-1: // 비교할 종료 시간이 현재 시작시간 -1초보다 크면 cnt++
                cnt += 1
        if cnt > answer: // max값 재설정
            answer = cnt
    return answer
