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
	<title><spring:message code="system_name" />
	</title>
	<link href="common/static/h-ui/css/H-ui.min.css" rel="stylesheet"
		  type="text/css" />
	<link href="common/static/h-ui.admin/css/H-ui.login.css"
		  rel="stylesheet" type="text/css" />
	<link href="common/static/h-ui.admin/css/style.css" rel="stylesheet"
		  type="text/css" />
	<link href="common/lib/Hui-iconfont/1.0.8/iconfont.css" rel="stylesheet"
		  type="text/css" />
	<script type="text/javascript">
		function flushCode() {
			document.getElementById("codeimg").src = "imageServlet?random="
					+ Math.random();
		}
	</script>
</head>


<body>

<div class="loginWraper">
	<div id="loginform" class="loginBox">
		<div style="margin-top:-30px;">
			<h2 align=center>
				<spring:message code="system_name" />
			</h2>
		</div>
		<form class="form form-horizontal"
			  action="${pageContext.request.contextPath}/User/login.do"
			  method="post">
			<div class="row cl">
				<label class="form-label col-xs-3"><i class="Hui-iconfont">&#xe60d;</i>
				</label>
				<div class="formControls col-xs-8">
					<input id="" name="s_0" type="text" placeholder="账户"
						   class="input-text size-L">
				</div>
			</div>
			<div class="row cl">
				<label class="form-label col-xs-3"><i class="Hui-iconfont">&#xe60e;</i>
				</label>
				<div class="formControls col-xs-8">
					<input id="" name="s_1" type="password" placeholder="密码"
						   class="input-text size-L">
				</div>
			</div>
			<div class="row cl">
				<div class="formControls col-xs-8 col-xs-offset-3">
					<input class="input-text size-L" type="text" placeholder="验证码"
						   name="code" onblur="if(this.value==''){this.value='验证码:'}"
						   onclick="if(this.value=='验证码:'){this.value='';}" value="验证码:"
						   style="width:150px;"> <img id="codeimg"
													  src="imageServlet"
													  style="margin-left:20px;width:100px;height:40px;"
													  onclick="flushCode();" /> <a id="kanbuq"
																				   style="margin-left:30px;width:100px;height:40px;bgcolor:#000000;"
																				   href="register.jsp">注册新用户</a>
				</div>
			</div>
			<div class="row cl">
				<div class="formControls col-xs-8 col-xs-offset-3"></div>
			</div>
			<div class="row cl">
				<div class="formControls col-xs-8 col-xs-offset-3">
					<input name="" type="submit" class="btn btn-success radius size-L"
						   value="&nbsp;登&nbsp;&nbsp;&nbsp;&nbsp;录&nbsp;"> <input
						name="" type="reset" style="margin-left:80px;"
						class="btn btn-default radius size-L"
						value="&nbsp;取&nbsp;&nbsp;&nbsp;&nbsp;消&nbsp;"> <font
						style="margin-left:20px;" color=red><font color=red>${errMsg
						} </font> </font>
				</div>
			</div>
		</form>
	</div>
</div>

</body>
</html>