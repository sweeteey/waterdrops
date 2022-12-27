<%@ page language="java" contentType="text/html; charset=UTF-8"
		 pageEncoding="UTF-8"%>
<%@ include file="common.jsp"%>
<%
	String path = request.getContextPath();
	String basePath = request.getScheme() + "://"
			+ request.getServerName() + ":" + request.getServerPort()
			+ path + "/";
%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<base href="<%=basePath%>">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<title>注册界面</title>
	<link href="common/static/h-ui/css/H-ui.min.css" rel="stylesheet"
		  type="text/css" />
	<link href="common/static/h-ui.admin/css/style.css" rel="stylesheet"
		  type="text/css" />
	<link href="login/css/alogin.css" rel="stylesheet"
		  type="text/css" />
	<link href="common/lib/Hui-iconfont/1.0.8/iconfont.css" rel="stylesheet"
		  type="text/css" />
</head>


<body>

<div class="loginWraper">
	<div id="loginform" class="loginBox">
		<div style="margin-top:-25px;">
			<h2 align=center>
				<spring:message code="system_name" />
			</h2>
		</div>
		<form id="form1" runat="server" action="${pageContext.request.contextPath}/User/register.do" method="post">
			<input type="hidden" name="util.role" value="1" />
			<%--用户名--%>
			<div class="row cl">
				<label class="form-label col-xs-3"><i class="Hui-iconfont">&#xe60d;</i></label>
				<div class="formControls col-xs-8">
					<input class="input-text size-L" id="" type="text" name="s_0" placeholder="账户"/>
				</div>
			</div>

			<%--密码，身份--%>
			<div class="row cl">
				<label class="form-label col-xs-3"><i class="Hui-iconfont">&#xe60e;</i></label>
				<div class="formControls col-xs-8">
					<input class="input-text size-L" id="" type="password" name="s_1" placeholder="密码"/>
					<input type="hidden" name="s_11" value="user" />
				</div>
			</div>

			<%--姓名--%>
			<div class="row cl">
				<label class="form-label col-xs-3"><i class="Hui-iconfont">&#xe68e;</i></label>
				<div class="formControls col-xs-8">
					<input class="input-text size-L" id="" type="text" name="s_2" placeholder="姓名"/>
				</div>
			</div>

			<%--电话--%>
			<div class="row cl">
				<label class="form-label col-xs-3"><i class="Hui-iconfont">&#xe6c7;</i></label>
				<div class="formControls col-xs-8">
					<input class="input-text size-L" id="" type="text" name="s_5" placeholder="电话"/>
				</div>
			</div>

			<div class="row cl">
				<div class="formControls col-xs-8 col-xs-offset-3"></div>
			</div>
			<div class="row cl">
				<div class="formControls col-xs-8 col-xs-offset-3">
					<input name="" type="submit" class="btn btn-success radius size-L"
						   value="&nbsp;注&nbsp;&nbsp;&nbsp;&nbsp;册&nbsp;">
					<font color=red>${errMsg } </font>
					<a id="yizhuce"
					   style="margin-left:30px;width:100px;height:40px;bgcolor:#000000;"
					   href="login.jsp">已有帐号？登录</a>
				</div>
			</div>
		</form>
	</div>
</div>
</body>
</html>
