<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
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
<script type="text/javascript">
	function topPage() {

		var contextPath = "${pageContext.request.contextPath}";
		var field = document.getElementById("field").value;
		var fieldValue = document.getElementById("fieldValue").value;
		var pageNo = "${pageModel.topPageNo}";
		window.location = contextPath
				+ '/User/getAllUtil.do?pageModel.currentPageNo=' + pageNo
				+ '&field=' + field + '&fieldValue=' + fieldValue + '';
	}

	function previousPage() {
		var contextPath = "${pageContext.request.contextPath}";
		var field = document.getElementById("field").value;
		var fieldValue = document.getElementById("fieldValue").value;
		var pageNo = "${pageModel.previousPageNo}";
		window.location = contextPath
				+ '/User/getAllUtil.do?pageModel.currentPageNo=' + pageNo
				+ '&field=' + field + '&fieldValue=' + fieldValue + '';
	}

	function nextPage() {

		var contextPath = "${pageContext.request.contextPath}";
		var field = document.getElementById("field").value;
		var fieldValue = document.getElementById("fieldValue").value;
		var pageNo = "${pageModel.nextPageNo}";

		var locationTmp = contextPath
				+ '/User/getAllUtil.do?pageModel.currentPageNo=' + pageNo
				+ '&field=' + field + '&fieldValue=' + fieldValue + ''
		window.location = locationTmp;
	}

	function bottomPage() {
		var contextPath = "${pageContext.request.contextPath}";
		var field = document.getElementById("field").value;
		var fieldValue = document.getElementById("fieldValue").value;
		var pageNo = "${pageModel.buttomPageNo}";
		window.location = contextPath
				+ '/User/getAllUtil.do?pageModel.currentPageNo=' + pageNo
				+ '&field=' + field + '&fieldValue=' + fieldValue + '';
	}

	function datadel() {

		var ids = document.getElementsByName("id");
		var flag = 0;
		for ( var i = 0; i < ids.length; i++) {
			if (ids[i].checked) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			if(confirm("确定要删除吗")){                                           
				document.myform.submit();                                           
			}else{                                           
				return false;                                           
			}    
		} else {
			alert("至少选中一条记录");
			return false;
		}

	}
</script>
</head>
<body class="pos-r">
	<div>
		<nav class="breadcrumb"> <i class="Hui-iconfont">&#xe67f;</i> 首页
		<span class="c-gray en">&gt;</span> 用户管理 <span class="c-gray en">&gt;</span>
		用户列表 <a class="btn btn-success radius r"
			style="line-height:1.6em;margin-top:3px"
			href="javascript:location.replace(location.href);" title="刷新"><i
			class="Hui-iconfont">&#xe68f;</i> </a> </nav>
		<div class="page-container">
			<div class="text-c">
				<form action="${pageContext.request.contextPath}/User/getAllUtil.do">
					<select id="field" name="field" class="select"
						style="width:120px;height:32px;">

						<option <c:if test="${field == 's_2'}">selected</c:if> value="s_2" />
						姓名
						</option>
						<option <c:if test="${field == 's_3'}">selected</c:if> value="s_3" />
						出生日期
						</option>
						<option <c:if test="${field == 's_4'}">selected</c:if> value="s_4" />
						性别
						</option>
						<option <c:if test="${field == 's_5'}">selected</c:if> value="s_5" />
						联系方式
						</option>
						<option <c:if test="${field == 's_6'}">selected</c:if> value="s_6" />
						QQ
						</option>


					</select> <input type="text" name="fieldValue" id="fieldValue"
						value="${fieldValue }" placeholder=" 检索内容" style="width:250px"
						class="input-text">
					<button name="" id="" class="btn btn-success" type="submit">
						<i class="Hui-iconfont">&#xe665;</i> 搜索
					</button>
					&nbsp;&nbsp; <input class="btn btn-success" type="button"
						value="清空"
						onclick="javascript: document.getElementById('fieldValue').value='';" />
					&nbsp;&nbsp;
				</form>
			</div>
			<div class="cl pd-5 bg-1 bk-gray mt-20">
				<span class="l"><a href="javascript:;" onclick="datadel()"
					class="btn btn-danger radius"><i class="Hui-iconfont">&#xe6e2;</i>
						批量删除</a> <a class="btn btn-primary radius" style="margin-left:20px;"
					href="${pageContext.request.contextPath}/admin/User/saveOrUpdate.jsp"><i
						class="Hui-iconfont">&#xe600;</i> 添加</a> </span> <span class="r">检索列表<strong></strong>
				</span>
			</div>
			<div class="mt-20">
				<form 
					action="${pageContext.request.contextPath}/User/deleteManyUtil.do"
					name="myform" id="myform" method="post">
					<table
						class="table table-border table-bordered table-bg table-hover table-sort">
						<thead>
							<tr class="text-c">
								<th width="40"><input name="" type="checkbox" value="">&nbsp;全选
								</th>
								<th>姓名</th>
								<th>出生日期</th>
								<th>性别</th>
								<th>联系方式</th>
								<th>QQ</th>
								<th>身份类型</th>
								<th>操作</th>
							</tr>
						</thead>
						<tbody>
							<c:if test="${fn:length(pageModel.list) < 1}">
								<tr class="text-c va-m">
									<td colspan=52>无记录</td>
								</tr>
							</c:if>
							<c:forEach var="tmp" items="${pageModel.list}">
								<tr>
								<tr class="text-c va-m">
									<td><input name="id" value="${tmp.id }" type="checkbox">
									</td>
									<td>${tmp.s_2 }</td>
									<td>${tmp.s_3 }</td>
									<td>${tmp.s_4 }</td>
									<td>${tmp.s_5 }</td>
									<td>${tmp.s_6 }</td>
									<td><c:if test="${tmp.s_11 == 'admin'}">
											<spring:message code="sys_admin" />
										</c:if> <c:if test="${tmp.s_11 == 'user'}">
											<spring:message code="sys_user" />
										</c:if></td>
									<td class="td-manage"><a style="text-decoration:none"
										class="ml-5"
										href="${pageContext.request.contextPath}/User/selectUtil.do?id=${tmp.id }"
										title="编辑"><i class="Hui-iconfont">&#xe6df;</i> </a> <a
										style="text-decoration:none;margin-left:15px;" class="ml-5"
										href="${pageContext.request.contextPath}/User/deleteUtil.do?id=${tmp.id }"
										title="删除"><i class="Hui-iconfont">&#xe6e2;</i> </a>
									</td>
								</tr>

							</c:forEach>
						</tbody>
					</table>
				</form>

				<br />
				<table width="90%" height="30" border="0" align="center"
					cellpadding="0" cellspacing="0" class="rd1">
					<tr>
						<td nowrap class="rd19" height="2" width="36%">
							<div align="left">
								<font>&nbsp;共&nbsp;${pageModel.totalRecords}&nbsp;条</font>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<font>当前第</font>&nbsp; <font color="#FF0000">${pageModel.currentPageNo}</font>&nbsp;/&nbsp;${pageModel.totalPages}
								<font>页</font>
							</div></td>
						<td nowrap class="rd19" width="64%">
							<div align="right">
								<input name="btnTopPage" class="btn btn-inverse" type="button"
									id="btnTopPage" value="|&lt;&lt; " title="首页"
									onClick="javascript:topPage();"> <input
									name="btnPreviousPage" class="btn btn-inverse" type="button"
									id="btnPreviousPage" value=" &lt;  " title="上页"
									onClick="javascript:previousPage();"> <input
									name="btnNextPage" class="btn btn-inverse" type="button"
									id="btnNextPage" value="  &gt; " title="下页"
									onClick="javascript:nextPage();"> <input
									name="btnBottomPage" class="btn btn-inverse" type="button"
									id="btnBottomPage" value=" &gt;&gt;|" title="尾页"
									onClick="javascript:bottomPage();">
							</div></td>
					</tr>
				</table>

			</div>

		</div>

	</div>
</body>
</html>
