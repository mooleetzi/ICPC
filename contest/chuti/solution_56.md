<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config">
    MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });
</script>
## E\_异能爆炸

- 二项式拆分矩阵快速幂优化求解和式
- $S_n=S_{n-1}+(pn+q)^k$
- $S_n=S_{n-1}+[p(n-1)+(p+q)]^k$
- $S_n=S_{n-1}+\sum_{i=0}^kC_k^i[p(n-1)]^{k-i}(p+q)^i$
- 令$X_{n-1}=\big( (n-1)^k,(n-1)^{k-1},..,(n-1)^0,S_{n-1} \big)^T$
- 则$X_n=\big( n^k,n^{k-1},..,n^0,S_n \big)^T$
- 那么有转移矩阵
$$
A=\left[
\begin{matrix}
    C_k^0&C_k^1&...&C_k^k&0\\\\
    0&C_{k-1}^0&...&C_{k-1}^{k-1}&0\\\\
    0&...&...&...&0\\\\
    0&...&...&C_0^0&0\\\\
    C_k^0p^k&C_k^1p^{k-1}(p+q)&...&C_k^k(p+q)^k&1]
\end{matrix}
\right]
$$
- 再通过递推求出前20的组合数，便可以愉快AC啦
- 时间复杂度$O(k^3logn)$
- https://paste.ubuntu.com/p/yHW66vs8zv/

## C\_不起眼的盒子
- 题目大意: 给一个01字符串，求子串中1的个数在给定区间内的子串数目。
- 由于字符串长度较小，我们可以考虑$n^2$预处理出所有阶的异能团生成方式，然后对于每次$O(1)$查询啦。
- solution#1,
    - 关于k阶异能团，我们仅考虑左右端点均为1的情况，通过当前状态计算出此时附近所有的k阶异能团
    - 我们首先预处理出每个1左右0的个数记为$pre[i],next[i]$，那么对于一个左右端点均为1的子串，我们可以以公式$(pre[l]+1)\times(next[r]+1)$计算出附近的k阶异能团数目
    - 举个栗子:010101,我们假设求2阶，最先扫描的满足条件区间$[1,3]$，其能扩展的附近k阶异能团为$(pre[1]+1)\times(next[3]+1)=(1+1)\times(1+1)=4,\big([0,3],[0,4],[1,3],[1,4]\big)$
    - 套一个滑窗即可求得所有情况


- solution#2,
    - 对原串求一遍前缀和$pre$
    - 记录$cnt[i]$表示1个数为i的子串数目
    - 对k阶异能团，从左往右扫一遍，$pre[i]\ge k$时，答案累加$cnt[pre[i]-k]$，更新cnt数组
- 关于0阶的处理，找出只包含0的子串数目就行
- 时间复杂度$O(n^2+m)$
- *此题数据查询会有大于字符串长度的区间，需要判断，详见代码*
- [solution#1](https://paste.ubuntu.com/p/HCZmvVM2Jc/)
- [solution#2](https://paste.ubuntu.com/p/W3Cwwc79M5/)