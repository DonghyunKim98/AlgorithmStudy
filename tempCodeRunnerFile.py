from itertools import combinations


def get_kth_string_and_second_B_position(N, K):
    positions = list(combinations(range(N), 2))
    sorted_positions = sorted(positions)

    # K번째 조합을 찾는다
    b1, b2 = sorted_positions[K-1]

    # K번째 문자열을 생성
    string = ['A'] * N
    string[b1] = 'B'
    string[b2] = 'B'

    # 두 번째 B의 위치 찾기
    second_B_position = b2 + 1

    return ''.join(string), second_B_position


# 주어진 값으로 실행
N = 10
K = 24
kth_string, second_B_position = get_kth_string_and_second_B_position(N, K)
password_corrected = bin(second_B_position)[2:]

print(kth_string, second_B_position, password_corrected)
