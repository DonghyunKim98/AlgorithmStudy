from collections import defaultdict
from itertools import combinations


names = ["김동현", "윤용성", "강무성", "박진우", "임정민"]
problems = [15649, 1260, 2667, 15650,  9663, 15652, 2580, 2468,  15651, 7576,]
min_problems = len(problems) // len(names)

# 문제를 공평하게 분배하기 위해 문제 수를 최대한 균등하게 분배


def distribute_problems(names, problems):
    problem_distribution = defaultdict(list)
    remaining_problems = len(problems) % len(names)

    for i, name in enumerate(names):
        problem_distribution[name] = problems[i *
                                              min_problems:(i+1)*min_problems]

        if remaining_problems > 0:
            problem_distribution[name].append(problems[-remaining_problems])
            remaining_problems -= 1

    return problem_distribution

# 각 문제가 최소 2명 이상에게 분배되도록 조합을 구함


def distribute_problems_fairly(problem_distribution):
    for problem in problems:
        assigned_people = [
            name for name, problems in problem_distribution.items() if problem in problems]
        if len(assigned_people) < 2:
            for name in names:
                if name not in assigned_people and len(problem_distribution[name]) < min_problems + 1:
                    problem_distribution[name].append(problem)
                    break

    return problem_distribution


problem_distribution = distribute_problems(names, problems)
fair_problem_distribution = distribute_problems_fairly(problem_distribution)

for name, problems in fair_problem_distribution.items():
    print(f"{name}: {problems}")
