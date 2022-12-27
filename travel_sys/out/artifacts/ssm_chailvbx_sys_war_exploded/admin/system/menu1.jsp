<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<li><a class="Hui-iconfont"
	onclick="article_add('添加课程','${pageContext.request.contextPath}/admin/User/saveOrUpdate.jsp')"
	data-title="修改个人资料" href="javascript:;">修改个人资料</a>
</li>
<li><a href="javascript:;"
	onclick="article_add('添加课程','Lesson-add.html')"><i
		class="Hui-iconfont">&#xe616;</i> 课程管理</a>
</li>
<li><a href="javascript:;"
	onclick="article_add('添加班级课程','LessonGrade-add.html')"><i
		class="Hui-iconfont">&#xe616;</i> 班级课程</a>
</li>
<li><a href="javascript:;"
	onclick="article_add('添加缴费','UserMoney-add.html')"><i
		class="Hui-iconfont">&#xe616;</i> 缴费管理</a>
</li>
<li><a href="javascript:;"
	onclick="article_add('添加成绩','UserScore-add.html')"><i
		class="Hui-iconfont">&#xe616;</i> 成绩管理</a>
</li>
<li><a href="javascript:;"
	onclick="article_add('添加档案','Document-add.html')"><i
		class="Hui-iconfont">&#xe616;</i> 档案管理</a>
</li>
