#!/usr/bin/python
# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import sys
import warnings
from colorama import init, Fore

warnings.simplefilter(action='ignore', category=FutureWarning)


def DataPre(file_location):
    """
    :type file_location: 输入文件位置
    """
    with open(file_location) as f:
        lines = f.readlines()
    numOfLine = len(lines)
    matToReturn = np.zeros((numOfLine, 3))
    labelsVector = []
    pos = 0
    for line in lines:
        line = line.strip().split('\t')
        matToReturn[pos, :] = line[0: 3]
        labelsVector.append(int(line[-1]))
        pos += 1
    return matToReturn, labelsVector


def doPlot(datingData, datingLabels):
    conf = plt.figure()
    ax = conf.add_subplot(111)
    ax.scatter(datingData[:, 0], datingData[:, 1],  12.0 * np.array(datingLabels), 15.0 * np.array(datingLabels))
    plt.xlabel("Flight distance")
    plt.ylabel("Time spent on games")
    plt.title("Data distribution")
    plt.show()


def autoNorm(dataSet):
    """
    Desc:
        归一化特征值，消除特征之间量级不同导致的影响
    parameter:
        dataSet: 数据集
    return:
        归一化后的数据集 normDataSet

    归一化公式：
        Y = (X-Xmin)/(Xmax-Xmin)
        其中的 min 和 max 分别是数据集中的最小特征值和最大特征值。该函数可以自动将数字特征值转化为0到1的区间。
    """
    # 计算每种属性的最大值、最小值、范围
    minVal = dataSet.min(0)
    maxVal = dataSet.max(0)
    # 极差
    ranges = maxVal - minVal
    m = dataSet.shape[0]
    # 生成与最小值之差组成的矩阵
    # tile函数，对矩阵进行复制(m, 1)代表复制m行1列
    normDataSet = dataSet - np.tile(minVal, (m, 1))
    # 将最小值之差除以范围组成矩阵
    normDataSet = normDataSet / np.tile(ranges, (m, 1))
    return normDataSet, minVal, ranges


def classify(crt, dataSet, labels, k):
    # 数据条数
    dataSize = dataSet.shape[0]
    # 距离度量 度量公式为欧氏距离
    diffMat = np.tile(crt, (dataSize, 1)) - dataSet
    sqDiffMat = diffMat ** 2
    distances = sqDiffMat.sum(axis=1)
    sortedDistances = distances.argsort()
    labelCount = {}
    for i in range(k):
        thisLabel = labels[sortedDistances[i]]
        labelCount[thisLabel] = labelCount.get(thisLabel, 0) + 1
    sortedLabelCount = sorted(labelCount.items(), key=lambda item: item[1], reverse=True)
    return sortedLabelCount[0][0]


def main(file_location):
    resultList = ['辣眼睛', '还可以', '今晚有空吗']
    datingData, datingLabels = DataPre(file_location)
    doPlot(datingData, datingLabels)
    datingData, minVal, ranges = autoNorm(datingData)
    print(Fore.GREEN + '输入数据格式：\n'
          '\t玩视频游戏所耗时间百分比 每年获得的飞行常客里程数 每周消费的冰淇淋公升数 k值\n'
          '\t:exit 退出')
    print(Fore.RESET)
    while True:
        par_input = raw_input('请输入数据：\n')
        if par_input == ':exit':
            print('88')
            exit(0)
        par = map(float, par_input.split())
        if len(par) != 4:
            print('wrong input type')
            continue
        crt = np.array(par[0: 3])
        crt = (crt - minVal) / ranges
        if crt.max() > 1 or crt.min() < 0:
            print('wrong input type')
            continue
        res = classify(crt, datingData, datingLabels, int(par_input[3]))
        print('结果为 %s' % resultList[res-1])


if __name__ == '__main__':
    try:
        file_location = sys.argv[1]
    except IndexError, e:
        print(e.message)
        print('Enter the location of input file')
        exit(1)
    else:
        main(file_location)
