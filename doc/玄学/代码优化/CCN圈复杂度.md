## 关于软件度量中的圈复杂度
    
    首先看两个概念：
    NCSS（Non Commenting Source Statements）有效代码行，扣除注释。
    CCN（Cyclomatic Complexity Number），圈复杂度。
    1个方法的CCN值通常意味着我们需要多少个测试案例来覆盖其不同的路径。
    当CCN发生很大波动或者CCN很高的代码片段被变更时，意味改动引入缺陷风险高。
    根据资料，圈复杂度（或CC）大于10的方法存在很大的出错风险.
