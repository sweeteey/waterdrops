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

	<script type="text/javascript">
		function check(){
			var s_0 = document.getElementById("s_0");
			if('' == s_0.value.replace(/(^\s*)|(\s*$)/g, "") ){
				alert("请输入内容");
				s_0.value = "";
				s_0.focus();
				return false;
			}
			return true;
		}
	</script>
</head>
<body>
<div class="page-container">
	<div class="form form-horizontal">
		<form
				action="${pageContext.request.contextPath}/BaoxiaoFile/upload.do"
				method="post"	onsubmit="return check()"	enctype="multipart/form-data">
			<c:if test="${util.id != null}">
				<input name="id" value="${util.id }" type="hidden" />
			</c:if>
			<%--<div class="row cl">
                <label class="form-label col-xs-4 col-sm-2">发票上传：</label>
                <div class="formControls col-xs-8 col-sm-9">
                    <input type="file" name="myfiles" />
                    <font size="2" color="red">文件为空表示不修改文件</font>
                </div>
            </div> --%>
			<div class="row cl">
				<label class="form-label col-xs-4 col-sm-2"><span
						class="c-red"></span>审批状态：</label>
				<div class="formControls col-xs-8 col-sm-3">

					<span class="select-box"><select  class="select" name="baoxiaoStatus.id">
						<c:forEach var="type" items="${listBaoxiaoStatus}">
							<c:if test="${user_type == type.s_1 }">

							<option
									<c:if test="${type.id == util.baoxiaoStatus.id }">
										selected
									</c:if>
									value="${type.id }">
									${type.s_0 }
							</option>
							</c:if>
						</c:forEach>
					</select>
					</span>
				</div>
			</div>
			<div class="row cl">
				<label class="form-label col-xs-4 col-sm-2"><span
						class="c-red"></span>报销类型：</label>
				<div class="formControls col-xs-8 col-sm-3">

					<span class="select-box"><select  class="select" name="baoxiaoType.id">
						<c:forEach var="type" items="${listBaoxiaoType}">
							<option
									<c:if test="${type.id == util.baoxiaoType.id }">
										selected
									</c:if>
									value="${type.id }">
									${type.s_0 }
							</option>
						</c:forEach>
					</select>
					</span>
				</div>
			</div>
			<div class="row cl">
				<label class="form-label col-xs-4 col-sm-2"><span
						class="c-red"></span>部门信息：</label>
				<div class="formControls col-xs-8 col-sm-3">                    

					<span class="select-box"><select  class="select" name="xibie.id">
						<c:forEach var="type" items="${listXibie}">
							<option
									<c:if test="${type.id == util.xibie.id }">
										selected
									</c:if>
									value="${type.id }">
									${type.s_0 }
							</option>
						</c:forEach>
					</select>
					</span>
				</div>
			</div>
			<div class="row cl">
				<label class="form-label col-xs-4 col-sm-2"><span
						class="c-red"></span>申请人：</label>
				<div class="formControls col-xs-8 col-sm-3">                    
					<span class="select-box"> <c:if
							test="${(user_type == 'user' && (util.id == null || (util.id != null && util.user.id == user_id)))}">
							<select class="select" name="user.id">
								<c:forEach var="type" items="${listUser}">
									<c:if test="${type.id == user_id }">
										<option value="${type.id }">${type.s_2 }</option>
									</c:if>
								</c:forEach>
							</select>
					</c:if> <c:if
							test="${(user_type != 'user' || (util.id != null && util.user.id != user_id))}">
							<select class="select" name="user.id">
								<c:forEach var="type" items="${listUser}">
									<option
											<c:if test="${util.user.id !=null &&  type.id == util.user.id }">
												selected
											</c:if>
										<c:if test="${user_type == 'user' && types.id == id && util.id == null }">
											selected
										</c:if>
											value="${type.id }">${type.s_0 }</option>
								</c:forEach>
							</select>
					</c:if> </span>				</div>
			</div>
			<div class="row cl">
				<label class="form-label col-xs-4 col-sm-2"><span
						class="c-red"></span>花费总金额：</label>
				<div class="formControls col-xs-8 col-sm-9">
					<input type="text" class="input-text" name="s_3"
						   value="${util.s_3 }" placeholder="花费总金额" id="" name="">
				</div>
			</div>
			<div class="row cl">
				<label class="form-label col-xs-4 col-sm-2"><span
						class="c-red"></span>报销总金额：</label>
				<div class="formControls col-xs-8 col-sm-9">
					<input type="text" class="input-text" name="s_4"
						   value="${util.s_4 }" placeholder="报销总金额" id="" name="">
				</div>
			</div>
			<div class="row cl">
				<label class="form-label col-xs-4 col-sm-2">备注：</label>
				<div class="formControls col-xs-8 col-sm-9">
					<textarea class="textarea" name="s_5">${util.s_5 }</textarea>
				</div>
			</div>
			<div class="row cl">
				<div class="col-xs-8 col-sm-9 col-xs-offset-4 col-sm-offset-2">
					<button
							class="btn btn-primary radius" type="submit">
						<i class="Hui-iconfont">&#xe632;</i> 保存
					</button>
					<button onClick="layer_close();" class="btn btn-default radius"
							type="button">&nbsp;&nbsp;取消&nbsp;&nbsp;</button>&nbsp;&nbsp;
					<font style="margin-left:20px;" color=red>${errMsg } </font>

				</div>
			</div>
		</form>
	</div>
</div>

</body>
</html>                                                                                        
