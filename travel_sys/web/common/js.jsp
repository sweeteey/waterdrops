<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<!--_footer 作为公共模版分离出去-->
<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/lib/jquery/1.9.1/jquery.min.js"></script>
<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/lib/layer/2.4/layer.js"></script>
<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/static/h-ui/js/H-ui.min.js"></script>
<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/static/h-ui.admin/js/H-ui.admin.js"></script>
<!--/_footer 作为公共模版分离出去-->


<!--请在下方写此页面业务相关的脚本-->
<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/lib/My97DatePicker/4.8/WdatePicker.js"></script>
<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/lib/datatables/1.10.0/jquery.dataTables.min.js"></script>
<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/lib/laypage/1.2/laypage.js"></script>
<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/lib/jquery.contextmenu/jquery.contextmenu.r2.js"></script>

<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/lib/jquery.validation/1.14.0/jquery.validate.js"></script>
<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/lib/jquery.validation/1.14.0/validate-methods.js"></script>
<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/lib/jquery.validation/1.14.0/messages_zh.js"></script>
<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/lib/webuploader/0.1.5/webuploader.min.js"></script>
<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/lib/ueditor/1.4.3/ueditor.config.js"></script>
<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/lib/ueditor/1.4.3/ueditor.all.min.js">
	
</script>
<script type="text/javascript"
	src="${pageContext.request.contextPath}/common/lib/ueditor/1.4.3/lang/zh-cn/zh-cn.js"></script>


<script type="text/javascript">
	/*个人信息*/
	function myselfinfo() {
		layer.open({
			type : 1,
			area : [ '360px', '200px' ],
			fix : false, //不固定
			maxmin : true,
			shade : 0.4,
			title : '帮助信息',
			content : '<div style="margin-left:20px;margin-top:10px;">欢迎光临我的毕业设计！感谢老师精心指导....</div>'
		});
	}

	/*资讯-添加*/
	function article_add(title, url) {
		var index = layer.open({
			type : 2,
			title : title,
			content : url
		});
		layer.full(index);
	}
	/*图片-添加*/
	function picture_add(title, url) {
		var index = layer.open({
			type : 2,
			title : title,
			content : url
		});
		layer.full(index);
	}
	/*产品-添加*/
	function product_add(title, url) {
		var index = layer.open({
			type : 2,
			title : title,
			content : url
		});
		layer.full(index);
	}
	/*用户-添加*/
	function member_add(title, url, w, h) {
		layer_show(title, url, w, h);
	}
</script>



