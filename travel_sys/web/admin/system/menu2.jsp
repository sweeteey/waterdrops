<%@ page language="java" contentType="text/html; charset=UTF-8"
		 pageEncoding="UTF-8"%>

<dl id="menu-product">
	<dt>
		<i class="Hui-iconfont">&#xe705;</i> 个人资料<i
			class="Hui-iconfont menu_dropdown-arrow">&#xe6d5;</i>
	</dt>
	<dd>
		<ul>
			<li><a
					data-href="${pageContext.request.contextPath}/User/beforeinfo.do"
					data-title="修改个人资料" href="javascript:void(0)">修改个人资料</a>
			</li>
			<li><a
					data-href="${pageContext.request.contextPath}/User/beforepass.do"
					data-title="修改密码" href="javascript:void(0)">修改密码</a>
			</li>
		</ul>
	</dd>
</dl>

<c:if test="${user_type == 'admin'}">
	<dl id="menu-product">
		<dt>
			<i class="Hui-iconfont">&#xe636;</i> <a
				data-href="${pageContext.request.contextPath}/User/getAllUtil.do"
				data-title="用户管理" href="javascript:void(0)">用户管理</a><i
				class="Hui-iconfont menu_dropdown-arrow"><</i>
		</dt>
	</dl>
	<dl id="menu-product">
		<dt>
			<i class="Hui-iconfont">&#xe72d;</i> <a
				data-href="${pageContext.request.contextPath}/Gongao/getAllUtil.do"
				data-title="公告管理" href="javascript:void(0)">公告管理</a><i
				class="Hui-iconfont menu_dropdown-arrow"><</i>
		</dt>
	</dl>

	<dl id="menu-product">
		<dt>
			<i class="Hui-iconfont">&#xe620;</i> <a
				data-href="${pageContext.request.contextPath}/BaoxiaoType/getAllUtil.do"
				data-title="报销类型管理" href="javascript:void(0)">报销类型管理</a><i
				class="Hui-iconfont menu_dropdown-arrow"><</i>
		</dt>
	</dl>
	<dl id="menu-product">
		<dt>
			<i class="Hui-iconfont">&#xe621;</i> <a
				data-href="${pageContext.request.contextPath}/Xibie/getAllUtil.do"
				data-title="部门信息管理" href="javascript:void(0)">部门信息管理</a><i
				class="Hui-iconfont menu_dropdown-arrow"><</i>
		</dt>
	</dl>
	<dl id="menu-product">
		<dt>
			<i class="Hui-iconfont">&#xe6b7;</i> <a
				data-href="${pageContext.request.contextPath}/BaoxiaoFile/getAllUtil.do"
				data-title="报销审批" href="javascript:void(0)">报销审批</a><i
				class="Hui-iconfont menu_dropdown-arrow"><</i>
		</dt>
	</dl>
	<%--<dl id="menu-product">
		<dt>
			<i class="Hui-iconfont">&#xe620;</i> <a
				data-href="${pageContext.request.contextPath}/Travel/getAllUtil.do"
				data-title="出差审批" href="javascript:void(0)">出差审批</a><i
				class="Hui-iconfont menu_dropdown-arrow"><</i>
		</dt>
	</dl>--%>
</c:if>

<c:if test="${user_type == 'user'}">

	<dl id="menu-product">
		<dt>
			<i class="Hui-iconfont">&#xe72d;</i> <a
				data-href="${pageContext.request.contextPath}/Gongao/getAllUtil.do"
				data-title="公告查看" href="javascript:void(0)">公告查看</a><i
				class="Hui-iconfont menu_dropdown-arrow"><</i>
		</dt>
	</dl>

	<dl id="menu-product">
		<dt>
			<i class="Hui-iconfont">&#xe620;</i> <a
				data-href="${pageContext.request.contextPath}/BaoxiaoType/getAllUtil.do"
				data-title="报销类型查看" href="javascript:void(0)">报销类型查看</a><i
				class="Hui-iconfont menu_dropdown-arrow"><</i>
		</dt>
	</dl>
	<dl id="menu-product">
		<dt>
			<i class="Hui-iconfont">&#xe621;</i> <a
				data-href="${pageContext.request.contextPath}/Xibie/getAllUtil.do"
				data-title="部门信息查看" href="javascript:void(0)">部门信息查看</a><i
				class="Hui-iconfont menu_dropdown-arrow"><</i>
		</dt>
	</dl>
	<dl id="menu-product">
		<dt>
			<i class="Hui-iconfont">&#xe6b7;</i> <a
				data-href="${pageContext.request.contextPath}/BaoxiaoFile/getAllUtil.do"
				data-title="报销审批查看" href="javascript:void(0)">报销审批查看</a><i
				class="Hui-iconfont menu_dropdown-arrow"><</i>
		</dt>
	</dl>
	<%--<dl id="menu-product">
		<dt>
			<i class="Hui-iconfont">&#xe620;</i> <a
				data-href="${pageContext.request.contextPath}/Travel/getAllUtil.do"
				data-title="出差审批查看" href="javascript:void(0)">出差审批查看</a><i
				class="Hui-iconfont menu_dropdown-arrow"><</i>
		</dt>
	</dl>--%>
</c:if>