# 版本概述
## 概述
1. 新增向量检索功能，详情请参考[向量索引](https://github.com/alibaba/havenask/wiki/%E5%90%91%E9%87%8F%E7%B4%A2%E5%BC%95)。
2. 集成了广泛使用的开源分析器（jieba分析器），增强havenask的分词能力，详情请参考[jieba分析器](https://github.com/alibaba/havenask/wiki/Jieba%E5%88%86%E6%9E%90%E5%99%A8)。
## 代码分支
* [v0.2.2](https://github.com/alibaba/havenask/tree/v0.2.2)
## 镜像版本
### 开发镜像
```
doker hub: havenask/ha3_dev:0.2.2
阿里云镜像: registry.cn-hangzhou.aliyuncs.com/havenask/ha3_dev:0.2.2
```
### 运行镜像
```
doker hub: havenask/ha3_runtime:0.2.2
阿里云镜像: registry.cn-hangzhou.aliyuncs.com/havenask/ha3_runtime:0.2.2
```
# 功能变化列表
|  功能  | 状态 |
|  ----  | ----  |
| 向量检索  | 新增 |
| jieba分析器  | 新增 |
# bug fix列表
无
# 兼容性说明
## 配置兼容性
兼容以前版本的配置。
## 索引兼容性
兼容以前版本的索引。
## 性能变化
性能无变化。