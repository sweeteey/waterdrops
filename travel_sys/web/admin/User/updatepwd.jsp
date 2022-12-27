<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%
	String path = request.getContextPath();
	String basePath = request.getScheme() + "://"
			+ request.getServerName() + ":" + request.getServerPort()
			+ path + "/";
%>
<%@ include file="/common/css.jsp"%>
<%@ include file="/common/js.jsp"%>
<%@ include file="/common/taglib.jsp"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<base href="<%=basePath%>">
<title><spring:message code="system_name" /></title>

</head>
<body>
	<div class="page-container">
		<form
			action="${pageContext.request.contextPath}/User/updatepwd.do"
			method="post" class="form form-horizontal" id="form-article-add">
			
		<input name="id" value="${util.id }" type="hidden" />
			<div class="row cl">
				<label class="form-label col-xs-4 col-sm-2"><span
					class="c-red">*</span>原密码：</label>
				<div class="formControls col-xs-6 col-sm-3">
					<input name="s_3" id="util.s_3" class="input-text" type="text" />
				</div>

			</div>

			<div class="row cl">
				<label class="form-label col-xs-4 col-sm-2"><span
					class="c-red">*</span>新密码：</label>
				<div class="formControls col-xs-6 col-sm-3">
					<input name="s_4" id="util.s_4" class="input-text" type="text" />
				</div>

			</div>

			<div class="row cl">
				<label class="form-label col-xs-4 col-sm-2"><span
					class="c-red">*</span>确认新密码：</label>
				<div class="formControls col-xs-6 col-sm-3">
					<input name="s_5" id="util.s_5" class="input-text" type="text" />
				</div>
			</div>
	</div>

	<div class="row cl">
		<div class="col-xs-8 col-sm-9 col-xs-offset-4 col-sm-offset-2">
			<button class="btn btn-primary radius" type="submit">
				<i class="Hui-iconfont">&#xe632;</i> 保存
			</button>
			<button onClick="layer_close();" class="btn btn-default radius"
				type="button">&nbsp;&nbsp;取消&nbsp;&nbsp;</button>
			&nbsp;&nbsp; <font style="margin-left:20px;" color=red><font
				color=red>${errMsg } </font> </font>
		</div>
	</div>
	</form>
	</div>
</body>
</html>
