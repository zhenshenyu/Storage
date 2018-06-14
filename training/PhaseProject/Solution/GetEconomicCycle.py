# -*- coding: utf-8 -*-
from datetime import date
from pandas import read_csv, DataFrame
from math import isnan
from matplotlib.dates import DateFormatter
import matplotlib.pyplot as plt
import warnings

warnings.filterwarnings("ignore")


class EconomicCycleSolution(object):
    def __init__(self):
        # 数据集大小
        self._lines = None
        self._date = None
        # 四个参数
        self._kqi_grow = None
        self._ip_grow = None
        self._cpi = None
        self._ppi = None
        # 初始化计算经济增长与通货膨胀的参数
        self._a = 1
        self._b = 0
        self._c = 1
        self._d = 0
        # 经济增长
        self._growth = None
        # 通货膨胀水平
        self._inflation = None
        # 结果
        self._result = None

    def _set_kqi_grow(self, kqi_grow):
        self._kqi_grow = kqi_grow

    def _set_ip_grow(self, ip_grow):
        self._ip_grow = ip_grow

    def _set_cpi(self, cpi):
        if cpi is None:
            print('Missing CPI column!!')
            exit(1)
        self._cpi = cpi

    def _set_ppi(self, ppi):
        if ppi is None:
            print('Missing PPI column!!')
            exit(1)
        self._ppi = ppi

    def get_date(self):
        return self._date

    # 获取预估经济增长
    def get_growth(self):
        return self._growth

    # 获取通货膨胀水平
    def get_inflation(self):
        return self._inflation

    # 手动配置参数
    def set_para(self, a, b, c, d):
        self._a = a
        self._b = b
        self._c = c
        self._d = d

    # series对象的map函数
    @staticmethod
    def format_method(target):
        par = target.split('/')
        return date(int(par[0]), int(par[1]), int(par[2]))

    # 格式化日期列
    def _format_date(self):
        if self._date is None:
            print('Missing Date column. Please add Date Label to Date column')
        self._date = self._date.map(self.format_method)

    # 读取数据集
    def read_csv_file(self, location):
        """
        读取csv文件并进行预处理
        并填充缺失数据
        请在数据集的日期列加上标题"Date"
        :param location: 读取文件位置
        :type location: str
        """
        data = read_csv(location)
        # 获取输入行数
        self._lines = data.shape[0]
        self._date = data.get('Date', None)
        self._format_date()
        kqi = data.get('KQI', None)
        ip = data.get('IP', None)
        if kqi is None or ip is None:
            print('Missing KQI or IP column')
            exit(1)
        self._set_cpi(data.get('CPI', None))
        self._set_ppi(data.get('PPI', None))
        # 填充KQI与IP行
        for i in range(self._lines/12):
            for j in range(12):
                if isnan(kqi[i*12+j]):
                    if j == 0:
                        kqi[i * 12 + j] = 2 * kqi[i * 12 + j + 1] - kqi[i * 12 + j + 2]
                    else:
                        kqi[i * 12 + j] = 2 * kqi[i * 12 + j - 1] - kqi[i * 12 + j - 2]
                if isnan(ip[i*12+j]):
                    if j == 0:
                        ip[i * 12 + j] = 2 * ip[i * 12 + j + 1] - ip[i * 12 + j + 2]
                    else:
                        ip[i * 12 + j] = 2 * ip[i * 12 + j - 1] - ip[i * 12 + j - 2]
        # 计算KQI与IP的增长
        self._kqi_grow = kqi.copy()
        self._ip_grow = ip.copy()
        for i in range(self._lines/12):
            for j in range(12):
                if j == 0:
                    pass
                else:
                    self._kqi_grow[i * 12 + j] = kqi[i * 12 + j] - kqi[i * 12 + j - 1]
                    self._ip_grow[i * 12 + j] = ip[i * 12 + j] - ip[i * 12 + j - 1]
        for i in range(self._lines / 12):
            self._kqi_grow[i * 12] = 2 * self._kqi_grow[i * 12 + 1] - self._kqi_grow[i * 12 + 2]
            self._ip_grow[i * 12] = 2 * self._ip_grow[i * 12 + 1] - self._ip_grow[i * 12 + 2]

    # 计算经济增长与通货膨胀水平
    def compute_gi(self):
        self._growth = self._kqi_grow.add(self._b) + self._ip_grow.mul(self._a)
        self._inflation = self._cpi.add(self._d) + self._ppi.mul(self._c)

    # 做参数曲线图
    def do_para_plot(self):
        plt.figure(figsize=(30, 10))
        plt.plot(self._date, self._kqi_grow, 'r', label='kqi_grow', color='black', linewidth=2)
        plt.plot(self._date, self._ip_grow, 'r', label='ip_grow', color='red', linewidth=2)
        plt.plot(self._date, self._cpi, 'r', label='cpi', color='purple', linewidth=2)
        plt.plot(self._date, self._ppi, 'r', label='ppi', color='blue', linewidth=2)
        plt.hlines(0, self._date[0], self._date[self._lines-1])
        plt.xlabel('Date')
        plt.ylabel('Value')
        plt.title('Show paras')
        plt.show()

    # 设置窗口大小，对Growth取平均值
    def rolling_growth(self, window):
        """
        :param window: 窗口大小
        :type window: int
        """
        self._growth = self._growth.rolling(window=window).mean()

    # 设置窗口大小，对Growth取平均值
    def rolling_inflation(self, window):
        """
            :param window: 窗口大小
            :type window: int
        """
        self._inflation = self._inflation.rolling(window=window).mean()

    # 做经济增长与通货膨胀谁水平预估图
    def do_res_plot(self):
        plt.figure(figsize=(30, 10))
        plt.plot(self._date, self._growth, 'r', label='Growth', color='red', linewidth=2)
        plt.plot(self._date, self._inflation, 'r', label='Inflation', color='green', linewidth=2)
        plt.hlines(0, self._date[0], self._date[self._lines - 1])
        plt.xlabel('Date')
        plt.ylabel('Value')
        plt.title('Estimate Growth and Inflation')
        plt.show()

    @staticmethod
    def _judge_type(growth, inflation):
        if growth > 0:
            if inflation > 0:
                return 'Overheat'
            else:
                return 'Recovery'
        else:
            if inflation > 0:
                return 'Stagflation'
            else:
                return 'Reflation'

    # 计算最后结果
    def compute_result(self):
        self._result = self._growth.copy()
        for i in range(self._lines):
            self._result[i] = self._judge_type(self._growth[i], self._inflation[i])

    # 结果存为csv文件
    def save_as_csv(self, location):
        """
        :param location: 文件存储位置
        """
        data = {
            'Date': self._date,
            'Type': self._result
        }
        result = DataFrame(data=data)
        result.to_csv(location)
