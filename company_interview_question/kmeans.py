#coding=utf-8

#参考：https://blog.csdn.net/zouxy09/article/details/17589329
import numpy as np
import math
import random

'''
题目：实现kmeans算法
'''

def cal_euclidean_dist(x, y):
    return np.sqrt(np.sum(np.power(x-y, 2)))

def init_centers(data_set, k):
    n, dim = data_set.shape
    centers = np.zeros((k, dim))
    for i in range(k):
        idx = int(random.uniform(0, n))
        centers[i, :] = data_set[idx, :]
    return centers

def kmeans(data_set, k):
    n = data_set.shape[0]
    cluster_assign = np.mat(np.zeros((n, 2)))
    cluster_change = True

    centers = init_centers(data_set, k)
    while cluster_change:
        cluster_change = False
        for i in xrange(n):
            min_dist = float('inf') #math.inf
            min_idx = 0
            for j in range(k):
                dist = cal_euclidean_dist(centers[j, :], data_set[i, :])
                if dist<min_dist:
                    min_dist = dist
                    min_idx = j
            if cluster_assign[i,0] != min_idx:
                cluster_change = True
                cluster_assign[i, :] = min_idx, min_dist**2

        for j in range(k):
            points_in_cluster = data_set[np.nonzero(cluster_assign[:,0].A == j)[0]]
            centers[j,:] = np.mean(points_in_cluster, axis=0)
    print "end of kmeans"
    print centers
    print cluster_assign
    return centers, cluster_assign


#------------------------------------------

def main():
    data_set = []
    with open('data/data_kmeans.txt', 'r') as f:
        for line in f:
            items = line.strip().split('\t')
            data_set.append([float(items[0]), float(items[1])])
    data_set = np.mat(data_set)
    k = 4
    centers, cluster_assign = kmeans(data_set, k)

if __name__ == "__main__":
    main()

