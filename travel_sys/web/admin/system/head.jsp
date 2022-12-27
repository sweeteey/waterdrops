<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<div id="dcHead">
	<div id="head">
		<div class="logo">
			<a href="index.html" style="color: #fff;"><img
				src="${pageContext.request.contextPath}/common/images/dclogo.gif"
				alt="logo"> <spring:message code="sys_name" />
			</a>
		</div>
		<div class="nav">
			<ul>
				<li class="M"><a href="JavaScript:void(0);" class="topAdd">新建</a>
					<div class="drop mTopad">
						<a href="product.php?rec=add">商品</a> <a href="article.php?rec=add">文章</a>
						<a href="nav.php?rec=add">自定义导航</a> <a href="show.html">首页幻灯</a> <a
							href="page.php?rec=add">单页面</a> <a href="manager.php?rec=add">管理员</a>
						<a href="link.html"></a>
					</div>
				</li>
				<li><a href="../index.php" target="_blank">查看站点</a></li>
				<li><a href="index.php?rec=clear_cache">清除缓存</a></li>
				<li><a href="http://www.mycodes.net" target="_blank">帮助</a></li>
				<li class="noRight"><a href="module.html">DouPHP+</a></li>
			</ul>
			<ul class="navRight">
				<li class="M noLeft"><a href="JavaScript:void(0);">您好，admin</a>
					<div class="drop mUser">
						<a href="manager.php?rec=edit&id=1">编辑我的个人资料</a> <a
							href="manager.php?rec=cloud_account">设置云账户</a>
					</div>
				</li>
				<li class="noRight"><a href="login.php?rec=logout">退出</a></li>
			</ul>
		</div>
	</div>
</div>