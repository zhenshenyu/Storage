#!/usr/bin/python
# -*- coding: utf-8 -*-
from GetEconomicCycle import EconomicCycleSolution


def main():
    ecs = EconomicCycleSolution()
    ecs.read_csv_file('MACRO.csv')
    # 更改参数值
    ecs.set_para(2, 0, 0, -3)
    ecs.compute_gi()
    # 平滑化数据
    ecs.rolling_growth(7)
    ecs.rolling_inflation(5)
    # 效果图
    ecs.do_res_plot()
    ecs.compute_result()
    ecs.save_as_csv('Result.csv')
    print('结果已存至Result.csv')


if __name__ == '__main__':
    main()
